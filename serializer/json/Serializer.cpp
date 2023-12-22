#include "Serializer.hpp"
#include "../../document/Document.hpp"
#include "../../document/Slide.hpp"
#include "../../document/Item.hpp"
#include "../../document/BoundingBox.hpp"
#include "../../document/TextAttributes.hpp"
#include "../../document/PenAttributes.hpp"
#include "../../document/Point.hpp"

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

void Serializer::serializeDocument(Document& doc, QJsonDocument& jsonDoc)
{
    QJsonObject jsonObj;
    QJsonArray jsonArray;
    
    jsonObj["slidesCount"] = static_cast<int>(doc.getSlidesCount());
    for(auto slide : doc){
        serializeSlide(slide, jsonArray);
    }
    jsonObj["slides"] = jsonArray;

    jsonDoc.setObject(jsonObj);
}

void Serializer::serializeSlide(std::shared_ptr<Slide> slide, QJsonArray& slideArray)
{
    QJsonObject jsonObj;
    QJsonArray jsonArray;

    jsonObj["itemCount"] = static_cast<int>(slide->getItemCount());
    
    for(auto item : *slide){
        serializeItem(item,jsonArray);
    }
    jsonObj["items"] = jsonArray;

    slideArray.append(jsonObj);
}

void Serializer::serializeItem(std::shared_ptr<Item> item , QJsonArray& itemArray){
    QJsonObject jsonObj;

    jsonObj["itemTag"] = static_cast<int>(item->tag());
    jsonObj["itemType"] = QString::fromStdString(item->type());
    jsonObj["BoundingBox"] = serializeBoundingBox(item->getBoundingBox());
    jsonObj["PenAttributes"] = serializePenAttributes(item->getPenAttributes());
    jsonObj["TextAttributes"] = serializeTextAttributes(item->getTextAttributes());

    itemArray.append(jsonObj);
}

QJsonObject Serializer::serializeBoundingBox(const BoundingBox& box)
{
    QJsonObject jsonObj;
    jsonObj["TopLeft"] = serializePoint(box.getTopLeft());
    jsonObj["BottomRight"] = serializePoint(box.getBottomRight());
    return jsonObj;
}

QJsonObject Serializer::serializePenAttributes(const PenAttributes& penAttr)
{
    QJsonObject jsonObj;
    jsonObj["color"] = QString::fromStdString(penAttr.getColor());
    jsonObj["style"] = QString::fromStdString(penAttr.getStyle());
    jsonObj["width"] = penAttr.getWidth();
    return jsonObj;
}

QJsonObject Serializer::serializeTextAttributes(const TextAttributes &textAttr)
{
    QJsonObject jsonObj;
    jsonObj["text"] = QString::fromStdString(textAttr.getText());
    jsonObj["size"] = textAttr.getSize();
    return jsonObj;
}

QJsonObject Serializer::serializePoint(const Point& point) {
    QJsonObject pointObj;
    pointObj["x"] = point.x();
    pointObj["y"] = point.y();
    return pointObj;
}
