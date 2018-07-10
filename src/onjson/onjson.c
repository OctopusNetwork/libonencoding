#include <stdlib.h>

#include "cjson/cJSON.h"

#include "libonplatform/ocnet_string.h"
#include "libonplatform/ocnet_malloc.h"

#include "onjson/onjson.h"

struct ocnet_json {
    cJSON   *cjson;
};

ocnet_json_t *ocnet_json_init(char *json)
{
    ocnet_json_t *onjson = (ocnet_json_t *)malloc(sizeof(ocnet_json_t));
    cJSON *c_json = cJSON_Parse(json);

    if (NULL == c_json) {
        free(onjson);
        return NULL;
    }
    onjson->cjson = c_json;

    return (void *)json;
}

static cJSON *__json_item(cJSON *ocnet_json, char *key, int type)
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

int ocnet_json_get_item_int(ocnet_json_t *ocnet_json, char *key, int *value)
{
    cJSON *item = NULL;

    if (NULL == (item = __json_item(
                    ocnet_json->cjson, key, cJSON_Number))) {
        return -1;
    }

    *value = item->valueint;
    return 0;
}

int ocnet_json_get_item_bool(ocnet_json_t *ocnet_json, char *key, char *value)
{
    cJSON *item = NULL;

    if (NULL == (item = __json_item(
                    ocnet_json->cjson, key, cJSON_True))) {
        if (NULL == (item = __json_item(
                        ocnet_json->cjson, key, cJSON_False))) {
            return -1;
        }
    }

    *value = item->valueint;
    return 0;
}

int ocnet_json_get_item_string(ocnet_json_t *ocnet_json, char *key, char *str, int max_len)
{
    cJSON *item = NULL;

    if (NULL == (item = __json_item(
                    ocnet_json->cjson, key, cJSON_String))) {
        return -1;
    }

    if (max_len < ocnet_strlen(item->valuestring) + 1) {
        return -1;
    }

    ocnet_memset(str, 0x0, max_len);
    ocnet_strncpy(str, item->valuestring, ocnet_strlen(item->valuestring));

    return 0;
}

void ocnet_json_final(ocnet_json_t *ocnet_json)
{
    cJSON_Delete(ocnet_json->cjson);
    free(ocnet_json);
}
