#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

class HelloApplication : public Wt::WApplication {
public:
    HelloApplication(const Wt::WEnvironment& env);

private:
    Wt::WLineEdit *nameEdit_;
    Wt::WText *greeting_;

    void greet();
};

HelloApplication::HelloApplication(const Wt::WEnvironment& env)
    : Wt::WApplication(env)
{
    setTitle("Hello world");                      // Устанавливаем заголовок страницы

    root()->addWidget(new Wt::WText("Your name, please? ")); // Добавляем текстовый элемент

    nameEdit_ = new Wt::WLineEdit(root());        // Добавляем поле ввода
    nameEdit_->setFocus();                         // Устанавливаем фокус на поле ввода

    Wt::WPushButton *button = new Wt::WPushButton("Greet me.", root()); // Добавляем кнопку
    button->setMargin(5, Wt::Side::Left);          // Устанавливаем отступы кнопки

    root()->addWidget(new Wt::WBreak());           // Добавляем перевод строки

    greeting_ = new Wt::WText(root());             // Добавляем текстовый элемент
    greeting_->setMargin(Wt::WLength::Auto, Wt::Side::Left); // Устанавливаем отступы текста

    button->clicked().connect(this, &HelloApplication::greet); // Подключаем обработчик события
}

void HelloApplication::greet()
{
    greeting_->setText("Hello there, " + nameEdit_->text()); // Обновляем текстовый элемент
}

int main(int argc, char **argv)
{
    return Wt::WRun(argc, argv, [](const Wt::WEnvironment &env) {
        return std::make_unique<HelloApplication>(env);
    });
}