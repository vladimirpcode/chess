enum class ChessPieceType{
    PAWN,
    KNIGHT,
    BISHOP,
    ROCK,
    KING,
    QUEEN,
    BLANK
};

enum class Color{
    BLACK,
    WHITE
};

class ChessPiece{
public:
    ChessPiece(ChessPieceType, Color);
    ChessPieceType type();
    int weight();
    Color color();
private:
    ChessPieceType _type;
    int _weight;
    Color _color;
};