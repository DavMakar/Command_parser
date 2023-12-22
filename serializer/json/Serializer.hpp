#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

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

#include <memory>

class Serializer {
public:
    void serializeDocument(Document&, QJsonDocument&);
private:
    void serializeSlide(std::shared_ptr<Slide>, QJsonArray&);
    void serializeItem(std::shared_ptr<Item>, QJsonArray&);
    QJsonObject serializeBoundingBox(const BoundingBox&);
    QJsonObject serializePenAttributes(const PenAttributes&);
    QJsonObject serializeTextAttributes(const TextAttributes&);
    QJsonObject serializePoint(const Point&);
};

#endif //SERIALIZER_HPP
