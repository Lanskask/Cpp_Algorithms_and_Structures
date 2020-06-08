load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "my_boost_asio",
    srcs = ["example1.cpp"],
    deps = [
        # "@boost_asio//boost_asio"
        "@boost_asio//:asio"
    ]
)
