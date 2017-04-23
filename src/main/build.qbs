import qbs

Application {
    name: "main"

    files: [
        "filters.cpp",
        "main.cpp",
        "filters.h",
        "fourier.h",
        "signal.cpp",
        "signal.h",
    ]

    Depends {
        name: "cpp"
    }
}
