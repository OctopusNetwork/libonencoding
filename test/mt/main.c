#include <stdlib.h>
#include <stdio.h>

#include "onjson.h"

int main(int argc, char *argv[])
{
    char *test_json = "{\"a\": \"atest\", \"b\": 125, \"c\": true, \"d\": false}";
    ocnet_json_t *ocnet_json = ocnet_json_init(test_json);

    char str[1024] = {0};
    int int_value = 0;
    char char_value = 0;

    if (NULL == ocnet_json) {
        return -1;
    }

    if (ocnet_json_get_item_string(ocnet_json, "a", str, 1024) < 0) {
        printf("fail to get a value\n");
    } else {
        printf("a's value: %s\n", str);
    }

    if (ocnet_json_get_item_int(ocnet_json, "b", &int_value) < 0) {
        printf("fail to get b value\n");
    } else {
        printf("b's value: %d\n", int_value);
    }

    if (ocnet_json_get_item_bool(ocnet_json, "c", &char_value) < 0) {
        printf("fail to get c value\n");
    } else {
        printf("c's value: %d\n", char_value);
    }

    if (ocnet_json_get_item_bool(ocnet_json, "d", &char_value) < 0) {
        printf("fail to get d value\n");
    } else {
        printf("d's value: %d\n", char_value);
    }

    ocnet_json_final(ocnet_json);
    return 0;
}
