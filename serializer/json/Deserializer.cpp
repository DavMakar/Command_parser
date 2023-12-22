#include "Deserializer.hpp"
#include "../../document/Document.hpp"
#include "../../document/Slide.hpp"
#include "../../document/Item.hpp"
#include "../../document/BoundingBox.hpp"
#include "../../document/TextAttributes.hpp"
#include "../../document/PenAttributes.hpp"
#include "../../document/Point.hpp"

std::unique_ptr<Document> Deserializer::deserializeDocument(const QJsonDocument &jsonDoc)
{
    auto document = std::make_unique<Document>();

    int slidesCount = jsonDoc["slidesCount"].toInt();
    
    QJsonArray slidesArray = jsonDoc["slides"].toArray();
    for (const auto& slide : slidesArray) {
        QJsonObject slideObj = slide.toObject();
        auto newSlide = deserializeSlide(slideObj);
        document->appendSlide(newSlide); //TODO add newSlide function
    }

    return document;
}

std::shared_ptr<Slide> Deserializer::deserializeSlide(const QJsonObject& jsonObj){
    int itemCount = jsonObj["itemCount"].toInt();
    auto slide = std::make_shared<Slide>();
    QJsonArray itemsArray = jsonObj["items"].toArray();
    for(const auto& item : itemsArray){
        QJsonObject itemObj = item.toObject();
        auto newItem = deserializeItem(itemObj);
        slide->addItem(newItem);
    }
}

std::shared_ptr<Item> Deserializer::deserializeItem(const QJsonObject& jsonObj){
    Item::Item_tag tag = m_reg.findItem(jsonObj["itemType"].toString().toStdString());
    BoundingBox box = deserializeBoundingBox(jsonObj["BoundingBox"].toObject());
    PenAttributes penAttr = deserializePenAttributes(jsonObj["PenAttributes"].toObject());
    TextAttributes textAttr = deserializeTextAttributes(jsonObj["TextAttributes"].toObject());
    return std::make_unique<Item>(tag, box,penAttr,textAttr);
}

BoundingBox Deserializer::deserializeBoundingBox(const QJsonObject& jsonObj){
    Point topLeft = deserializePoint(jsonObj["TopLeft"].toObject());
    Point bottomRight = deserializePoint(jsonObj["BottomRight"].toObject());
    return {topLeft,bottomRight};
};

PenAttributes Deserializer::deserializePenAttributes(const QJsonObject& jsonObj){
    std::string color = jsonObj["color"].toString().toStdString();
    std::string style = jsonObj["style"].toString().toStdString();
    int width = jsonObj["width"].toInt();
    return {color,style,width};
}

TextAttributes Deserializer::deserializeTextAttributes(const QJsonObject& jsonObj){
    std::string text = jsonObj["text"].toString().toStdString();
    int size = jsonObj["size"].toInt();
    return {text,size};
};

Point Deserializer::deserializePoint(const QJsonObject& jsonObj){
    double x = jsonObj["x"].toDouble();
    double y = jsonObj["y"].toDouble();
    return {x,y};
};