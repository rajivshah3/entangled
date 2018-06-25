workspace(name = "org_iota_entangled")

git_repository(
    name = "rules_iota",
    commit = "65be5655cd0bd511d7f120f248db20ec742a614b",
    remote = "https://github.com/rajivshah3/rules_iota.git",
)

android_sdk_repository(
    name = "androidsdk",
    api_level = 19,
)

android_ndk_repository(
    name = "androidndk",
    api_level = 14,
)

load("@rules_iota//:defs.bzl", "iota_deps")

iota_deps()
