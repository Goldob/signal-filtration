import qbs

import 'config.js' as Config

Project {
    name: 'Filtracja'

    Application {
        name: 'Prototyp'

        files: [
            "src/core/list.h",
        ].concat([
            "src/core/list.cpp",
        ].concat([
            'src/cli.cpp'
        ].concat(Config.CORE_FILES)))

        cpp.includePaths: [ Config.CORE_PATH ]

        Depends { name: 'cpp' }
    }

    // TODO Wykonaj testy
    Product {
        name: 'Testy'

        files: [
            'test/fourier_test.cpp',
            'test/filters_test.cpp'
        ].concat(Config.CORE_FILES)

        cpp.includePaths: [ Config.CORE_PATH ]

        Depends { name: 'Qt.testlib' }
    }

    // TODO Zbuduj dokumentację
    Product {
        name: 'Dokumentacja'
    }
}
