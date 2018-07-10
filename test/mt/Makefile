rootdir := $(shell pwd)/../../../..
project := ubuntu-base

include $(rootdir)/build/project/$(project).mk
include $(rootdir)/build/common/common.mk

####
##  Application targets
####
DEP_HEADERS += $(incdir)/libonencoding/onjson

apps = mt_encoding

mt_encoding_SRCS = $(rootdir)/source/libonencoding/test/mt/main.c
mt_encoding_ARCHIVES = onencoding cjson onplatform
mt_encoding_LDLIBS = -lm
mt_encoding_DISTSOLIBS =

include $(rootdir)/build/utils/app.mk
