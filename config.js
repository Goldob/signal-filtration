// Project configuration file

//==============================================================================
// PATHS
//==============================================================================

var CORE_PATH = 'src/core'

//==============================================================================
// SOURCES
//==============================================================================

var CORE_FILES = prependAll([
    'filters.h',
    'fourier.h',
    'signal.h',
    'filters.cpp',
    'signal.cpp'
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
