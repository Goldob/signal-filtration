// Project configuration file

//==============================================================================
// PATHS
//==============================================================================

var CORE_PATH = 'src/core'

//==============================================================================
// HEADERS & SOURCES
//==============================================================================

var CORE_FILES = prependAll([
    /* headers */
    'filters.h',
    'fourier.h',
    'signal.h',
    'list.h',

    /* sources */
    'filters.cpp',
    'fourier.cpp',
    'signal.cpp',
    'list.cpp'
], CORE_PATH)

//==============================================================================
// HELPER FUNCTIONS
//==============================================================================

function prepend (filename, basePath) {
    return basePath + '/' + filename
}


function prependAll (filenames, basePath) {
    return filenames.map(function (filename) {
        return prepend(filename, basePath)
    })
}
