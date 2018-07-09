rootdir := $(shell pwd)/../../..
project := ubuntu-base

include $(rootdir)/build/common/inc.mk
ifeq ($(hostmaketype), windows)
rootdir := ../../..
endif

####
##  Application targets
####
DEP_HEADERS += $(incdir)/libonencoding/onjson

apps = mt_encoding

mt_encoding_SRCS = $(rootdir)/encoding/test/mt/main.c
mt_encoding_ARCHIVES = libonencoding cJSON libonplatform
mt_encoding_LDLIBS = -lm
mt_encoding_DISTSOLIBS =

include $(rootdir)/build/utils/app.mk
