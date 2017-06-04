/* File filtracja.h */
#ifndef FILTRACJA_INCLUDED
#define FILTRACJA_INCLUDED

#include <QMainWindow>
#include <QThreadPool>
#include <QSignalMapper>

#include "ui_filtracja.h"

#include "about_dialog.h"
#include "signal.h"
#include "filters.h"

#include "tasks/task.h"
#include "tasks/read_file.h"
#include "tasks/save_file.h"
#include "tasks/filter_signal.h"

#include "widgets/welcome_screen.h"
#include "widgets/filter_control_panel.h"
#include "widgets/filter_preview.h"

/*!
 * \brief Filtracja jest głównym oknem programu. Odpowiada za zarządzanie poszczególnymi komponentami.
 */
class Filtracja : public QMainWindow {
    Q_OBJECT

    public:
        /*!
         * \brief Tworzy nową instancję okna.
         * \param parent
         */
        explicit Filtracja              (QWidget * parent = nullptr);
        ~Filtracja                      ();

    private slots:
        void on_actionOpen_triggered    ();
        void on_actionSave_triggered    ();
        void on_actionSaveAs_triggered  ();
        void on_actionAbout_triggered   ();

        void readFile                   (QString fileName);
        void saveFile                   (QString fileName, dsp::signal input);
        void filterSignal               (dsp::filter filter);

        void onFileReadSuccess          (QString fileName, dsp::signal output);
        void onFileReadFailure          (QString errorMessage);
        void onFileSaveSuccess          (QString fileName);
        void onFileSaveFailure          (QString errorMessage);
        void onSignalFiltered           (dsp::signal output);

    private:
        void cancelTask                 (Task * task_ptr);
        void updateTitle                ();

        Ui::Filtracja       *   m_ui                    = new Ui::Filtracja;
        AboutDialog         *   m_aboutDialog           = new AboutDialog(this);

        FilterPreview       *   m_filterPreview         = nullptr;

        QThreadPool         *   m_globalThreadPool      = QThreadPool::globalInstance();

        bool                    m_readInProgress        = false;
        bool                    m_saveInProgress        = false;
        bool                    m_filteringInProgress   = false;

        ReadFileTask        *   m_readFileTask          = nullptr;
        SaveFileTask        *   m_saveFileTask          = nullptr;
        FilterSignalTask    *   m_filterSignalTask      = nullptr;

        QString                 m_fileName;
        dsp::signal             m_input;
        dsp::signal             m_output;
};

#endif /* !FILTRACJA_INCLUDED */
