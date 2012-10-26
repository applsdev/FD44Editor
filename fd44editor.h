#ifndef FD44EDITOR_H
#define FD44EDITOR_H

#include <QMainWindow>
#include <QByteArray>
#include <QClipboard>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
#include <QUrl>

#include "motherboards.h"

namespace Ui {
class FD44Editor;
}

class FD44Editor : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit FD44Editor(QWidget *parent = 0);
    ~FD44Editor();

    void openImageFile(QString path);

private slots:
    void openImageFile();
    void saveImageFile();
    void enableSaveButton();
    void enableDtsKeyEdit(int index);
    void enableMacMagicEdit(int index);
    void enableDtsMagicCombobox(int index);

private:
    Ui::FD44Editor *ui;
    QString lastError;
    bios_t opened;

    bios_t readFromBIOS(const QByteArray & data);
    QByteArray writeToBIOS(const QByteArray & data, const bios_t & bios);

    bios_t readFromUI();
    bool writeToUI(bios_t bios);

    void dragEnterEvent(QDragEnterEvent* event);
    void dropEvent(QDropEvent* event);
};

#endif // FD44EDITOR_H
