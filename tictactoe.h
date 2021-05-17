#ifndef TIC_TAC_TOE
#define TIC_TAC_TOE
class TicTacToe{
	private:
		char space = ' ';
		char (*checkerboard)[3];
		bool checkWin(bool player,int x,int y);
	public:
		TicTacToe();
		~TicTacToe();
		void showBoard(void);
		void init(void);
		bool placePiece(bool player,int x, int y);
		void play();
};

#endif
