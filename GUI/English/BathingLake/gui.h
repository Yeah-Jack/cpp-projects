#ifndef GUI_H
#define GUI_H

#include "lake.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class GUI;
}
QT_END_NAMESPACE

/**
 * @brief Main GUI widget for interacting with the lake management system.
 */
class GUI : public QWidget {
  Q_OBJECT

public:
  GUI(QWidget *parent = nullptr);
  ~GUI();

private slots:
  /**
   * @brief Slot triggered when the water temperature button is clicked.
   * Displays the current temperature.
   */
  void on_waterTemperatureBtn_clicked();

  /**
   * @brief Slot triggered when the water quality button is clicked. Displays
   * the current quality.
   */
  void on_waterQualityBtn_clicked();

  /**
   * @brief Slot triggered when the add person button is clicked. Adds a new
   * person if names are provided.
   */
  void on_addPersonBtn_clicked();

  /**
   * @brief Slot triggered when the remove person button is clicked. Removes the
   * selected person.
   */
  void on_removePersonBtn_clicked();

  /**
   * @brief Slot triggered when the rent lounger button is clicked. Rents a new
   * lounger if possible.
   */
  void on_rentLoungerBtn_clicked();

  /**
   * @brief Slot triggered when the remove lounger button is clicked. Removes
   * the selected lounger.
   */
  void on_removeLoungerBtn_clicked();

  /**
   * @brief Slot triggered when the view visitors button is clicked. Displays
   * the number of visitors.
   */
  void on_viewVisitorsBtn_clicked();

  /**
   * @brief Slot triggered when the park bike button is clicked. Logs a bike
   * parking action.
   */
  void on_parkBikeBtn_clicked();

private:
  Ui::GUI *ui;
  Lake *lake;
  void updateWaterTemperatureList();
  void updatePeopleList();
  void updateLoungerList();
};
#endif // GUI_H
