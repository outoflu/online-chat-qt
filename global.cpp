#include "global.h"

std::function<void(QWidget*)> repolish=[](QWidget* q_window){
    q_window->style()->unpolish(q_window);
    q_window->style()->polish(q_window);
};
