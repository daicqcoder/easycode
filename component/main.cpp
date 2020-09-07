#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QStringList>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a (argc, argv);
    QStringList List;
    QString Line = "a|b|c|d";
    List = Line.split("|");
    qDebug()<<"List is: "<<List;
    QString Line_After;
    Line_After = List.join("|");
    qDebug()<<"Line After is: "<< Line_After;

    QJsonObject root;
    root["FirstName"] = "Dai";
    root["LastName"] = "Chu";
    root["Age"] = "26";
    // creat neasted object
    QJsonObject Address;
    Address["Street"] = "89ATruongDing";
    Address["City"] = "HaNoi";
    Address["Country"] = "vietNam";
    root["Address"] = Address;
    QJsonArray PhoneNumber;
    PhoneNumber.push_back("+840982682627");
    PhoneNumber.push_back("+84982692698");
    root["PhoneNumber"] = PhoneNumber;
//    QJsonValue address = root.value("Address");
//    QJsonObject Address_From_Root = address.toObject();
//    qDebug()<<Address_From_Root;
//    QJsonValue street_of_root = Address_From_Root.value("Street");
//    QString street = street_of_root.toString();
//    qDebug()<<"Street is: "<<street;
    QFile file;
    QString val;
    file.setFileName("/home/daicq/component/Information_member_class.js");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val  = file.readAll();
    file.close();
    QByteArray b = val.toUtf8();
    qDebug()<<"Cover json file QString to QByteArray: "<< b;
    QJsonDocument d = QJsonDocument::fromJson(b);
    qDebug()<<"JsonDocument convert: "<< d;
    QJsonObject obj= d.object();
    qDebug()<<"Covert to Json Object: "<< obj;
    return a.exec();
}
