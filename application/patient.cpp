#include "patient.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QString>
#include <QDate>
#include <QTableWidget>
#include "mainwindow.h"
#include <QtCharts>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QTableWidget>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QHttpMultiPart>
#include <QHttpPart>
#include <QDragEnterEvent>
#include <QDropEvent>

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

#include <QCamera>
#include <QCameraImageCapture>
#include <QTimer>

#include <windows.h>
#include <iostream>
#include <string>
#include <CommCtrl.h> // Ajoutez cette ligne pour inclure CommCtrl.h


using namespace QtCharts;
Patient::Patient()
{
    prenom = "";
    nom = "";
    telephone = 0;
    dos_med = "";
    sexe = "";
    naissance = QDate::currentDate();
    image = QByteArray();
}

Patient::Patient(QString prenom, QString nom, int telephone, QString dos_med, QString sexe, QDate naissance, QByteArray image)
    : prenom(prenom), nom(nom), telephone(telephone), dos_med(dos_med), sexe(sexe), naissance(naissance), image(image) { }

 bool Patient::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO TABLE_PATIENT (PRENOM, NOM, TELEPHONE, DOS_MED, SEXE, NAISSANCE, IMAGE) "
                  "VALUES (:prenom, :nom, :telephone, :dos_med, :sexe, :naissance, :image)"); // Ajoutez :image
    query.bindValue(":prenom", prenom);
    query.bindValue(":nom", nom);
    query.bindValue(":telephone", telephone);
    query.bindValue(":dos_med", dos_med);
    query.bindValue(":sexe", sexe);
    query.bindValue(":naissance", naissance);
    query.bindValue(":image", image);
    if(query.exec()) {
        return true;
    } else {
        qDebug() << "Error adding patient: " << query.lastError();
        return false;
    }
}

 bool Patient::modifier(int id, QByteArray imageData) {


    QSqlQuery query;
    query.prepare("UPDATE TABLE_PATIENT SET PRENOM = :prenom, NOM = :nom, TELEPHONE = :telephone, DOS_MED = :dos_med, SEXE = :sexe, IMAGE = :imageData WHERE ID = :id"); // Ajoutez IMAGE = :image
    query.bindValue(":prenom", prenom);
    query.bindValue(":nom", nom);
    query.bindValue(":telephone", telephone);
    query.bindValue(":dos_med", dos_med);
    query.bindValue(":sexe", sexe);
     query.bindValue(":imageData", imageData); // Ajoutez cette ligne
    query.bindValue(":id", id);
    if(!query.exec()) {
        qDebug() << "Erreur : " << query.lastError();
        return false;
    }

    return true;
}

 bool Patient::deleteFromDatabase() {
    QSqlQuery query;
    query.prepare("DELETE FROM TABLE_PATIENT WHERE ID = :id");
    query.bindValue(":id", id);
    if(!query.exec()) {
        qDebug() << "Erreur de suppression : " << query.lastError();
        return false;
    }
    return true;
}
void Patient::setId( int id) {
    this->id = id;
}



void Patient::updateStats(QLabel *label, QStackedWidget *stackedWidget) {


    qDebug()<<" d5ltttttttttttttttttttt";
    QSqlQuery queryHomme;
    queryHomme.prepare("SELECT COUNT(*) FROM TABLE_PATIENT WHERE sexe = 'Homme'");
    queryHomme.exec();
    queryHomme.next();
    int nombreHomme = queryHomme.value(0).toInt();


    QSqlQuery queryFemme;
    queryFemme.prepare("SELECT COUNT(*) FROM TABLE_PATIENT WHERE sexe = 'Femme'");
    queryFemme.exec();
    queryFemme.next();
    int nombreFemme = queryFemme.value(0).toInt();

    // Créer un nouveau graphique à barres
    QBarSet *set0 = new QBarSet("Homme");
    QBarSet *set1 = new QBarSet("Femme");

    *set0 << nombreHomme;
    *set1 << nombreFemme;

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques par sexe");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "Sexe";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);


    stackedWidget->insertWidget(5, chartView);


    stackedWidget->setCurrentIndex(5);


    label->setText("Homme: " + QString::number(nombreHomme) + "\nFemme: " + QString::number(nombreFemme));
}
 void Patient::displayTable(QTableWidget *table, bool test) {
Connection c;


if (test){
    QSqlDatabase::database().transaction();
    QSqlQuery Query_Get_Data(c.get_db());
    Query_Get_Data.prepare("SELECT * FROM TABLE_PATIENT");

    if (Query_Get_Data.exec()) {
        int currentRow = 0;

            table->setRowCount(10);
            qDebug() <<Query_Get_Data.size();


        while (Query_Get_Data.next()) {
                table->setRowCount(currentRow+1);
                QByteArray imageData = Query_Get_Data.value("IMAGE").toByteArray();
                    QPixmap image;
                    image.loadFromData(QByteArray::fromBase64(imageData), "PNG");


                    QPixmap circularImage(image.size());
                    circularImage.fill(Qt::transparent);
                    QPainter painter(&circularImage);
                    QPainterPath path;
                    path.addEllipse(image.rect());
                    painter.setClipPath(path);
                    painter.drawPixmap(0, 0, image);


                    QLabel *imageLabel = new QLabel;
                    imageLabel->setPixmap(circularImage.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation)); // Ajustez la taille comme vous le souhaitez


                        table->setCellWidget(currentRow, 1, imageLabel);
                QTableWidgetItem *item0 = new QTableWidgetItem(Query_Get_Data.value("ID").toString());
               QTableWidgetItem *item2 = new QTableWidgetItem(Query_Get_Data.value("NOM").toString());
               QTableWidgetItem *item3 = new QTableWidgetItem(Query_Get_Data.value("PRENOM").toString());
                QTableWidgetItem *item4 = new QTableWidgetItem(Query_Get_Data.value("NAISSANCE").toString());
                 QTableWidgetItem *item5 = new QTableWidgetItem(Query_Get_Data.value("TELEPHONE").toString());
              QTableWidgetItem *item6 = new QTableWidgetItem(Query_Get_Data.value("SEXE").toString());
               QTableWidgetItem *item7 = new QTableWidgetItem(Query_Get_Data.value("DOS_MED").toString());

                 table->setItem(currentRow, 0, item0);
                 table->setItem(currentRow, 2, item2);
                table->setItem(currentRow, 3, item3);
                 table->setItem(currentRow, 4, item4);
                 table->setItem(currentRow, 5, item5);
                table->setItem(currentRow, 6, item6);
               table->setItem(currentRow, 7, item7);
                currentRow++;
                qDebug() << "Nombre de lignes récupérées : " << currentRow;
            }
        }

    QSqlDatabase::database().commit();

}

 }


 QString Patient::performFaceAnalysis(const QImage &image) {
     QNetworkAccessManager* manager = new QNetworkAccessManager();
     QUrl url("https://faceanalyzer-ai.p.rapidapi.com/faceanalysis");
     QNetworkRequest request(url);

     request.setRawHeader("X-RapidAPI-Key", qgetenv("RAPIDAPI_KEY")); // Replace YOUR_API_KEY_HERE with your actual API key

     QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

     QHttpPart imagePart;
     imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/jpeg")); // Assuming the image is JPEG
     imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"image\""));

     QByteArray imageData;
     QBuffer buffer(&imageData);
     buffer.open(QIODevice::WriteOnly);
     image.save(&buffer, "JPEG");

     imagePart.setBody(imageData);
     multiPart->append(imagePart);

     QNetworkReply *reply = manager->post(request, multiPart);
     multiPart->setParent(reply); // Ensure multiPart is deleted when reply is deleted

     // Wait for the reply to finish
     QEventLoop loop;
     QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
     loop.exec();

     QString outputText;
     if (reply->error() == QNetworkReply::NoError) {
         QByteArray responseData = reply->readAll();
         qDebug() << "Response: " << responseData;

         // Parse the JSON response
         QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
         QJsonObject jsonObject = jsonResponse.object();

         // Check if faces are detected
         QJsonArray facesArray = jsonObject["body"].toObject()["faces"].toArray();
         if (!facesArray.isEmpty()) {
             // Extract facial features of the first face
             QJsonObject faceObject = facesArray[0].toObject();
             QJsonObject facialFeaturesObject = faceObject["facialFeatures"].toObject();

             // Construct the output text
             outputText += "Gender: " + facialFeaturesObject["Gender"].toString() + "\n";
             outputText += "Smile: " + QString(facialFeaturesObject["Smile"].toBool() ? "Yes" : "No") + "\n";
             outputText += "Eyeglasses: " + QString(facialFeaturesObject["Eyeglasses"].toBool() ? "Yes" : "No") + "\n";
             outputText += "Sunglasses: " + QString(facialFeaturesObject["Sunglasses"].toBool() ? "Yes" : "No") + "\n";

             QJsonObject ageRangeObject = facialFeaturesObject["AgeRange"].toObject();
             int ageLow = ageRangeObject["Low"].toInt();
             int ageHigh = ageRangeObject["High"].toInt();
             outputText += "Age Range: " + QString::number(ageLow) + "-" + QString::number(ageHigh) + " years old\n";

             QJsonArray emotionsArray = facialFeaturesObject["Emotions"].toArray();
             QStringList emotions;
             for (const auto &emotion : emotionsArray) {
                 emotions.append(emotion.toString());
             }
             outputText += "Emotions: " + emotions.join(", ");

             qDebug() << "Output Text: " << outputText;
         } else {
             qDebug() << "No face detected!";
         }
     } else {
         qDebug() << "Error: " << reply->errorString();
     }

     reply->deleteLater();
     return outputText;
 }


 // Définissez un message personnalisé pour détecter les clics sur l'icône de notification
 #define WM_ICON_NOTIFY (WM_USER + 1)
 Patient sessionD;
 void Patient::showNotification(const std::wstring& title, const std::wstring& message) {
     // Initialisez les données de l'icône de notification
         NOTIFYICONDATA nid;
         memset(&nid, 0, sizeof(NOTIFYICONDATA));
         nid.cbSize = sizeof(NOTIFYICONDATA);
         nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_INFO;
         nid.uCallbackMessage = WM_ICON_NOTIFY; // Utilisez le message personnalisé pour détecter les clics sur l'icône
         nid.hIcon = LoadIcon(NULL, IDI_INFORMATION);
         wcscpy_s(nid.szTip, title.c_str());

         // Affichez la notification toast
         Shell_NotifyIcon(NIM_ADD, &nid);
         Shell_NotifyIcon(NIM_MODIFY, &nid); // Rafraîchir l'icône pour la rendre visible dans la zone de notification
         nid.uTimeout = 3000; // Durée d'affichage de la notification en millisecondes
         nid.dwInfoFlags = NIIF_INFO;
         wcscpy_s(nid.szInfoTitle, title.c_str());
         wcscpy_s(nid.szInfo, message.c_str());
         Shell_NotifyIcon(NIM_MODIFY, &nid); // Affichez la notification toast
 }



