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
            'src/gui/tasks/task.cpp',
            'src/gui/tasks/task.h',
            'src/gui/tasks/filter_signal.cpp',
            'src/gui/tasks/filter_signal.h',
            'src/gui/tasks/save_file.cpp',
            'src/gui/tasks/save_file.h',
            'src/gui/tasks/read_file.cpp',
            'src/gui/tasks/read_file.h',
            'src/gui/widgets/welcome_screen.cpp',
            'src/gui/widgets/welcome_screen.h',
            'src/gui/widgets/filter_preview.cpp',
            'src/gui/widgets/filter_preview.h',
            'src/gui/widgets/filter_control_panel.cpp',
            'src/gui/widgets/filter_control_panel.h',
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
        Depends { name: 'Qt.charts' }
    }
}
