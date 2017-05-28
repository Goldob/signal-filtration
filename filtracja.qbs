import qbs

import 'config.js' as Config

Project {
    name: 'Filtracja'

    Application {
        name: 'Program konsolowy'

        files: [ 'src/cli.cpp' ]
                    .concat(Config.CORE_FILES)

        cpp.includePaths: [ Config.CORE_PATH ]

        Depends { name: 'cpp' }
    }

    Application {
        name: 'Program graficzny'

        files: [
            'src/gui/filtracja.cpp',
            'src/gui/filtracja.h',
            'src/gui/about_dialog.cpp',
            'src/gui/about_dialog.h',
            'src/gui/main.cpp',
            'res/ui/filtracja.ui',
            'res/ui/about_dialog.ui'
        ].concat(Config.CORE_FILES)

        cpp.includePaths: [
            'src/gui',
            Config.CORE_PATH
        ]

        Depends { name: 'cpp' }
        Depends { name: 'Qt.widgets' }
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

        files: [
            "src/core/dsp.h"
        ]
    }
}
