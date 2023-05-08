#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

int main(int argc, char** argv) {
    Wt::WApplication app(argc, argv);
    Wt::WContainerWidget* container = new Wt::WContainerWidget();
    Wt::WLineEdit* edit = new Wt::WLineEdit();
    Wt::WPushButton* button = new Wt::WPushButton("Click me!");
    Wt::WText* text = new Wt::WText();
        container->addWidget(edit);
        container->addWidget(button);
        container->addWidget(text);
        button->clicked().connect([=] {
        text->setText(edit->text());
        });
    app.root()->addWidget(container);
    return app.exec();
}