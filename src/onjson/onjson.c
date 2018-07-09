#include <stdlib.h>

#include "cJSON.h"

#include "ocnet_string.h"
#include "ocnet_malloc.h"

#include "onjson.h"

void *ocnet_json_init(char *json)
{
    cJSON *c_json = cJSON_Parse(json);

    if (NULL == c_json) {
        return NULL;
    }

    return (void *)c_json;
}

static cJSON *__json_item(void *ocnet_json, char *key, int type)
{
    cJSON *item = cJSON_GetObjectItem(ocnet_json, key);

    if (NULL == item) {
        return NULL;
    }

    if (type != item->type) {
        return NULL;
    }

    return item;
}

int ocnet_json_get_item_int(void *ocnet_json, char *key, int *value)
{
    cJSON *item = NULL;

    if (NULL == (item = __json_item(
                    ocnet_json, key, cJSON_Number))) {
        return -1;
    }

    *value = item->valueint;
    return 0;
}

int ocnet_json_get_item_bool(void *ocnet_json, char *key, char *value)
{
    cJSON *item = NULL;

    if (NULL == (item = __json_item(
                    ocnet_json, key, cJSON_True))) {
        if (NULL == (item = __json_item(
                        ocnet_json, key, cJSON_False))) {
            return -1;
        }
    }

    *value = item->valueint;
    return 0;
}

int ocnet_json_get_item_string(void *ocnet_json, char *key, char *str, int max_len)
{
    cJSON *item = NULL;

    if (NULL == (item = __json_item(
                    ocnet_json, key, cJSON_String))) {
        return -1;
    }

    if (max_len < ocnet_strlen(item->valuestring) + 1) {
        return -1;
    }

    ocnet_memset(str, 0x0, max_len);
    ocnet_strncpy(str, item->valuestring, ocnet_strlen(item->valuestring));

    return 0;
}

void ocnet_json_final(void *ocnet_json)
{
    cJSON_Delete(ocnet_json);
}
