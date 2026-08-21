#include "widget.h"
#include "controller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Controller erzeugt und verwaltet intern das Model (Data).
    Controller controller;

    // View erhält nur einen Pointer auf den Controller (kein Besitz).
    Widget fenster(&controller);

    // Controller erhält im Gegenzug einen Pointer auf die View, falls er
    // z.B. später aktiv Aktualisierungen anstoßen möchte.
    controller.setView(&fenster);

    fenster.show();
    return a.exec();
}
