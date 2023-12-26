#ifndef DESERIALIZER_HPP
#define DESERIALIZER_HPP

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "../../document/itemRegistry.hpp"

class Document;
class Slide;
class BoundingBox;
class TextAttributes;
class PenAttributes;
class QJsonArray;
class QJsonObject;
class QJsonDocument;
class Point;
class Item;

class Deserializer {
public:
    std::unique_ptr<Document> deserializeDocument(const QJsonDocument& jsonDoc);

private:
    std::unique_ptr<Slide> deserializeSlide(const QJsonObject& jsonObj);
    std::shared_ptr<Item> deserializeItem(const QJsonObject& jsonObj);
    BoundingBox deserializeBoundingBox(const QJsonObject& jsonObj);
    PenAttributes deserializePenAttributes(const QJsonObject& jsonObj);
    TextAttributes deserializeTextAttributes(const QJsonObject& jsonObj);
    Point deserializePoint(const QJsonObject& jsonObj);

private:
    ItemRegistry m_reg;
};

#endif // DESERIALIZER_HPP
