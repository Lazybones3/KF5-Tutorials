#include <cstdlib>

#include <QApplication>
#include <QCommandLineParser>

#include <KAboutData>
#include <KLocalizedString>

#include "mainwindow.h"

int main (int argc, char *argv[])
{
    QApplication app(argc, argv);
    KLocalizedString::setApplicationDomain("tutorial3");

    KAboutData aboutData(
        // The program name used internally. (componentName)
        QStringLiteral("tutorial3"),
        // A displayable program name string. (displayName)
        i18n("Tutorial 3"),
        // The program version string. (version)
        QStringLiteral("1.0"),
        // Short description of what the app does. (shortDescription)
        i18n("A simple text area using KAction etc."),
        // The license this code is released under
        KAboutLicense::GPL,
        // Copyright Statement (copyrightStatement = QString())
        i18n("(c) 2015"),
        // Optional text shown in the About box.
        // Can contain any information desired. (otherText)
        i18n("Some text..."),
        // The program homepage string. (homePageAddress = QString())
        QStringLiteral("http://example.com/"),
        // The bug report email address
        // (bugsEmailAddress = QLatin1String("submit@bugs.kde.org")
        QStringLiteral("submit@bugs.kde.org"));
    aboutData.addAuthor(i18n("Name"), i18n("Task"), QStringLiteral("your@email.com"),
                        QStringLiteral("http://your.website.com"), QStringLiteral("OSC Username"));
    KAboutData::setApplicationData(aboutData);

    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();
    aboutData.setupCommandLine(&parser);
    parser.process(app);
    aboutData.processCommandLine(&parser);

    MainWindow* window = new MainWindow();
    window->show();

    return app.exec();
}
