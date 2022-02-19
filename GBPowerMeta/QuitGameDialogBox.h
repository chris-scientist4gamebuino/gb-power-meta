// author: chris-scientist
// created at: 19/02/2022

#pragma once

#include "ADialogBox.h"

class QuitGameDialogBox : public ADialogBox {
  protected:
    void renderingText() const;
  public:
    QuitGameDialogBox();
};
