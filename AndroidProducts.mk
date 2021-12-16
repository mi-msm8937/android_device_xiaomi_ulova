#
# Copyright (C) 2021 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

PRODUCT_MAKEFILES := \
    $(LOCAL_DIR)/lineage_ulova.mk

COMMON_LUNCH_CHOICES := \
    lineage_ulova-user \
    lineage_ulova-userdebug \
    lineage_ulova-eng

PRODUCT_MAKEFILES += \
    $(LOCAL_DIR)/revengeos_ulova.mk

COMMON_LUNCH_CHOICES += \
    revengeos_ulova-user \
    revengeos_ulova-userdebug \
    revengeos_ulova-eng
