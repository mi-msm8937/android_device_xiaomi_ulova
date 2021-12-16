/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <android-base/file.h>

#include <libinit_msm8937.h>

static const variant_info_t ugglite_info = {
    .brand = "xiaomi",
    .device = "ugglite",
    .marketname = "",
    .model = "Redmi Note 5A",
    .build_description = "ugglite-user 7.1.2 N2G47H V11.0.3.0.NDFMIXM release-keys",
    .build_fingerprint = "xiaomi/ugglite/ugglite:7.1.2/N2G47H/V11.0.3.0.NDFMIXM:user/release-keys",
};

static const variant_info_t ugg_info = {
    .brand = "xiaomi",
    .device = "ugg",
    .marketname = "",
    .model = "Redmi Note 5A",
    .build_description = "ugg-user 7.1.2 N2G47H V11.0.2.0.NDKMIXM release-keys",
    .build_fingerprint = "xiaomi/ugg/ugg:7.1.2/N2G47H/V11.0.2.0.NDKMIXM:user/release-keys",
};

static const variant_info_t rolex_info = {
    .brand = "Xiaomi",
    .device = "rolex",
    .marketname = "",
    .model = "Redmi 4A",
    .build_description = "rolex-user 7.1.2 N2G47H V10.2.3.0.NCCMIXM release-keys",
    .build_fingerprint = "Xiaomi/rolex/rolex:7.1.2/N2G47H/V10.2.3.0.NCCMIXM:user/release-keys",
};

static const variant_info_t riva_info = {
    .brand = "Xiaomi",
    .device = "riva",
    .marketname = "",
    .model = "Redmi 5A",
    .build_description = "riva-user 7.1.2 N2G47H V10.1.1.0.NCKMIFI release-keys",
    .build_fingerprint = "Xiaomi/riva/riva:7.1.2/N2G47H/V10.1.1.0.NCKMIFI:user/release-keys",
};

static void determine_device()
{
    std::string fdt_model, proc_cmdline;

    android::base::ReadFileToString("/proc/cmdline", &proc_cmdline, true);
    if (proc_cmdline.find("S88503") != proc_cmdline.npos) {
        set_variant_props(rolex_info);
        return;
    }
    else if (proc_cmdline.find("S88505") != proc_cmdline.npos) {
        set_variant_props(riva_info);
        return;
    }

    android::base::ReadFileToString("/sys/firmware/devicetree/base/model", &fdt_model, true);
    if (fdt_model.find("MSM8917") != fdt_model.npos)
        set_variant_props(ugglite_info);
    else if (fdt_model.find("MSM8940") != fdt_model.npos)
        set_variant_props(ugg_info);
}

void vendor_load_properties() {
    determine_device();
    set_dalvik_heap_size();
#ifdef LIBINIT_MSM8937_MODS
    load_mods();
#endif
}
