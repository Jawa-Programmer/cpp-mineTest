#include <math.h>
#include <limits>

class Block 
{
	protected:
	int x,y,z;
	
	public:
	
	void drawLines()
	{
		glBegin(GL_LINES);
	
	//Верх
	
	glColor3f(0,0,0);
	glVertex3f(x,y,z );
	glVertex3f(x + 1, y, z);
	glVertex3f(x + 1, y, z + 1);
	glVertex3f(x, y, z + 1);
	
	//Лево

	glVertex3f(Block::x,Block::y, Block::z );
	glVertex3f(Block::x,Block::y, Block::z + 1 );
	glVertex3f(Block::x,Block::y - 1, Block::z + 1 );
	glVertex3f(Block::x,Block::y - 1, Block::z);
	
	//Право
	
	glVertex3f(Block::x + 1,Block::y, Block::z );
	glVertex3f(Block::x + 1,Block::y, Block::z + 1 );
	glVertex3f(Block::x + 1,Block::y - 1, Block::z + 1 );
	glVertex3f(Block::x + 1,Block::y - 1, Block::z);
	
	//Низ
	glVertex3f(Block::x,Block::y - 1,Block::z );
	glVertex3f(Block::x + 1,Block::y - 1,Block::z );
	glVertex3f(Block::x + 1,Block::y - 1,Block::z +1 );
	glVertex3f(Block::x,Block::y - 1,Block::z + 1);
	
	//Перед
	glVertex3f(Block::x,Block::y,Block::z );
	glVertex3f(Block::x,Block::y - 1,Block::z );
	glVertex3f(Block::x + 1,Block::y - 1,Block::z );
	glVertex3f(Block::x + 1,Block::y,Block::z );

	//Зад
	glVertex3f(Block::x,Block::y,Block::z + 1);
	glVertex3f(Block::x,Block::y - 1,Block::z + 1);
	glVertex3f(Block::x + 1,Block::y - 1,Block::z + 1);
	glVertex3f(Block::x + 1,Block::y,Block::z + 1);

	
	glEnd();
		}
	
	
	virtual int getX(){return x;}
	virtual int getY(){return y;}
	virtual int getZ(){return z;}
	
	static const int SIDE_TOP, SIDE_BOTTOM,SIDE_LEFT,SIDE_RIGHT,SIDE_FORWARD,SIDE_BACKWARD;
	
	Block(int x, int y, int z)
	{
	Block::x=x;
	Block::y=y;
	Block::z=z;
	}
	
	virtual bool isAir() {return false;}
	virtual bool IsSeeAtMe(float cX,float cY,float cZ, float rX,float rY, float rZ, float* len, int* side)
	{
		float min_len = std::numeric_limits<float>::max();
		
		
		float bx = x-cX, by=y-cY,bz=z-cZ;
		float L = hypot(hypot(rX,rY),rZ);
		int sd = -1;
		//проверка сверху
		{
			float xzl = hypot(rX,rZ);
			float xzL = xzl/rY*by;
			float tx = rX/xzl*xzL, tz = rZ/xzl*xzL;
				float ln = hypot(hypot(tx,by),tz);
				
			if((rX*tx>=0&&rY*by>=0&&rZ*tz>=0)&&(tx>bx&&tx<bx+1&&tz>bz&&tz<bz+1) && ln < min_len) 
			{
				min_len = ln;
				sd = SIDE_TOP;
				}
			
			}
		//проверка снизу
		{
			float xzl = hypot(rX,rZ);
			float xzL = xzl/rY*(by-1);
			float tx = rX/xzl*xzL, tz = rZ/xzl*xzL;

			float ln = hypot(hypot(tx,by-1),tz);

			if((rX*tx>=0&&rY*(by-1)>=0&&rZ*tz>=0)&&(tx>bx&&tx<bx+1&&tz>bz&&tz<bz+1) && ln< min_len) {
				
				min_len = ln;
				sd = SIDE_BOTTOM;
				}
			}
			//проверка слева
		{
			float yzl = hypot(rY,rZ);
			float yzL = yzl/rX*(bx);
			float ty = rY/yzl*yzL, tz = rZ/yzl*yzL;

			float ln = hypot(hypot(bx,ty),tz);

			if((rX*bx>=0&&rY*(ty)>=0&&rZ*tz>=0)&&(ty<by&&ty>by-1&&tz>bz&&tz<bz+1) && ln< min_len) {
				
				min_len = ln;
				sd = SIDE_LEFT;
				}
			}	
			//проверка справа
		{
			float yzl = hypot(rY,rZ);
			float yzL = yzl/rX*(bx+1);
			float ty = rY/yzl*yzL, tz = rZ/yzl*yzL;

			float ln = hypot(hypot(bx+1,ty),tz);

			if((rX*bx>=0&&rY*(ty)>=0&&rZ*tz>=0)&&(ty<by&&ty>by-1&&tz>bz&&tz<bz+1) && ln< min_len) {
				
				min_len = ln;
				sd = SIDE_RIGHT;
				}
			}
			//проверка спереди
		{
			float xyl = hypot(rX,rY);
			float xyL = xyl/rZ*(bz);
			float ty = rY/xyl*xyL, tx = rX/xyl*xyL;

			float ln = hypot(hypot(tx,ty),bz);

			if((rX*tx>=0&&rY*(ty)>=0&&rZ*bz>=0)&&(ty<by&&ty>by-1&&tx>bx&&tx<bx+1) && ln< min_len) {
				min_len = ln;
				sd = SIDE_FORWARD;
				}
			}
			//проверка сзади
		{
			float xyl = hypot(rX,rY);
			float xyL = xyl/rZ*(bz+1);
			float ty = rY/xyl*xyL, tx = rX/xyl*xyL;

			float ln = hypot(hypot(tx,ty),bz+1);

			if((rX*tx>=0&&rY*(ty)>=0&&rZ*bz>=0)&&(ty<by&&ty>by-1&&tx>bx&&tx<bx+1) && ln< min_len) {
				min_len = ln;
				sd = SIDE_BACKWARD;
				}
			}
			
			if(min_len < std::numeric_limits<float>::max())
			{
				(*len) = min_len;
				(*side) = sd;
				return true;
				}
				(*len) = -1;
				(*side) = -1;
				
		return false;
		}
	
	virtual void Draw()
	{
	}
	};

const int Block::SIDE_TOP = 0;
const int Block::SIDE_BOTTOM = 1;
const int Block::SIDE_LEFT= 2;
const int Block::SIDE_RIGHT = 3;
const int Block::SIDE_FORWARD = 4;
const int Block::SIDE_BACKWARD = 5;
