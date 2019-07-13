
class DirtBlock : public Block
{
	protected:
	static const float colors[6][3]; 
	
	public:
	
	DirtBlock(int x, int y, int z) : Block(x, y, z)
	{
		}
		
		virtual void Draw()
	{
	glBegin(GL_QUADS);
	
	//Верх
	int i = 0;
	glColor3f(colors[i][0],colors[i][1],colors[i][2]);
	glVertex3f(Block::x,Block::y,Block::z );
	glVertex3f(Block::x + 1,Block::y,Block::z );
	glVertex3f(Block::x + 1,Block::y,Block::z +1 );
	glVertex3f(Block::x,Block::y,Block::z + 1);
	i++;
	
	//Лево	
	glColor3f(colors[i][0],colors[i][1],colors[i][2]);
	glVertex3f(Block::x,Block::y, Block::z );
	glVertex3f(Block::x,Block::y, Block::z + 1 );
	glVertex3f(Block::x,Block::y - 1, Block::z + 1 );
	glVertex3f(Block::x,Block::y - 1, Block::z);
	i++;
	
	//Право
	
	glColor3f(colors[i][0],colors[i][1],colors[i][2]);
	glVertex3f(Block::x + 1,Block::y, Block::z );
	glVertex3f(Block::x + 1,Block::y, Block::z + 1 );
	glVertex3f(Block::x + 1,Block::y - 1, Block::z + 1 );
	glVertex3f(Block::x + 1,Block::y - 1, Block::z);
	i++;
	
	//Низ
	glColor3f(colors[i][0],colors[i][1],colors[i][2]);
	glVertex3f(Block::x,Block::y - 1,Block::z );
	glVertex3f(Block::x + 1,Block::y - 1,Block::z );
	glVertex3f(Block::x + 1,Block::y - 1,Block::z +1 );
	glVertex3f(Block::x,Block::y - 1,Block::z + 1);
	i++;
	
	//Перед
	glColor3f(colors[i][0],colors[i][1],colors[i][2]);
	glVertex3f(Block::x,Block::y,Block::z );
	glVertex3f(Block::x,Block::y - 1,Block::z );
	glVertex3f(Block::x + 1,Block::y - 1,Block::z );
	glVertex3f(Block::x + 1,Block::y,Block::z );
	i++;

	//Зад
	glColor3f(colors[i][0],colors[i][1],colors[i][2]);
	glVertex3f(Block::x,Block::y,Block::z + 1);
	glVertex3f(Block::x,Block::y - 1,Block::z + 1);
	glVertex3f(Block::x + 1,Block::y - 1,Block::z + 1);
	glVertex3f(Block::x + 1,Block::y,Block::z + 1);

	
	glEnd();
	
	
	}
	};
	
const float DirtBlock::colors[6][3]={{0,1,0},
			{0.5,0.3,0},
			{0.5,0.3,0},
			{0.5,0.3,0},
			{0.5,0.3,0},
			{0.5,0.3,0}};
