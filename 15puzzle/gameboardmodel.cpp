#include "gameboardmodel.h"
#include <random>
#include <QDebug>

GameBoardModel::GameBoardModel(QObject *parent, size_t size)
    : m_dimension {size},
      m_board(size * size)
{
    Q_UNUSED(parent)
    std::iota(m_board.begin(), m_board.end(), 1);
}

int GameBoardModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_board.size();
}

QVariant GameBoardModel::data(const QModelIndex &index, int role) const
{
    const int elementIndex {index.row()};
    if (!index.isValid() &&
            elementIndex < 0 &&
            elementIndex >= boardSize() &&
            role != Qt::DisplayRole)
    {
        return {};
    }

    const Tile& tile {m_board.at(elementIndex)};

    return QVariant::fromValue(static_cast<int>(tile.value));
}

void GameBoardModel::move(int index)
{
    qDebug() << "MOVE! " << index;
}

void GameBoardModel::shuffleBoard()
{
    std::random_device defaultRandomDevice;
    std::default_random_engine randomEngine {defaultRandomDevice()};
    do {
        std::shuffle(m_board.begin(), m_board.end(), randomEngine);
    }
    while (!isBoardValid());
}

bool GameBoardModel::isBoardValid() const
{
    return true;
}

size_t GameBoardModel::dimension() const
{
    return m_dimension;
}

size_t GameBoardModel::boardSize() const
{
    return m_dimension * m_dimension;
}
