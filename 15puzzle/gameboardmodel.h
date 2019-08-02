#ifndef GAMEBOARDMODEL_H
#define GAMEBOARDMODEL_H
#include <QAbstractListModel>

class GameBoardModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int dimension READ dimension CONSTANT)
public:
    static constexpr size_t DefaultDimension {5};
    GameBoardModel(QObject* parent = nullptr,
                   size_t size = DefaultDimension);

    int rowCount(const QModelIndex& parent) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Q_INVOKABLE void move(int index);
    struct Tile {
        size_t value;
        Tile& operator= (const size_t new_value) {
            value = new_value;
            return *this;
        }
        bool operator==(const size_t other) {
            return other == value;
        }
    };

    size_t dimension() const;
    size_t boardSize() const;

private:
    void shuffleBoard();
    bool isBoardValid() const;

    const size_t m_dimension;
    std::vector<Tile> m_board;
};

#endif // GAMEBOARDMODEL_H
