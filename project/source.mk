COMMON_INCLUDE_DIRS += $(rootdir)/$(MODULE)/include/onjson             \
                       $(incdir)/cJSON $(incdir)/libonplatform

COMMON_SRC_FILES := $(rootdir)/$(MODULE)/src/json/onjson.c

COMMON_INST_HEADER_DIRS += $(rootdir)/$(MODULE)/include
