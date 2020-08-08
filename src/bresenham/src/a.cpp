/* help: unicode glyphs for box drawing??? */
#include<iostream>
#include<iomanip>
#include<vector>
#include<array>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<random>
template<const size_t w,const size_t h>
class Raster{
	public:
		Raster(){
			mw=w;
			mh=h;
		};
		~Raster(){};
		void plot(std::ostream&pos){
			std::for_each(mr.begin(),mr.end(),[&pos](const auto&r){
				std::for_each(r.begin(),r.end(),[&pos](const char&c){
					pos<<c;
				});
				pos<<'\n';
			});
		}
		void fill(unsigned char pc){
			std::for_each(mr.begin(),mr.end(),[&pc](auto&r){
				std::for_each(r.begin(),r.end(),[&pc](auto&c){
					c=pc;
				});
			});
		};
		void putpixel(
			double x,
			double y,
			unsigned char pc
		){
			if(x>=0&&x<(int)mw&&y>=0&&y<(int)mh)mr[y][x]=pc;
		};
		void line(
			double x1,
			double y1,
			double x2,
			double y2,
			unsigned char pc
		){
			try{
			int x,y,dx,dy,dx1,dy1,px,py,xe,ye,i;
			dx=x2-x1;
			dy=y2-y1;
			dx1=fabs(dx);
			dy1=fabs(dy);
			px=2*dy1-dx1;
			py=2*dx1-dy1;
			if(dy1<=dx1){
				if(dx>=0){
					x=x1;y=y1;xe=x2;
				}else{
					x=x2;y=y2;xe=x1;
				}
				putpixel(x,y,pc);
				for(i=0;x<xe;i++){
					x=x+1;
					if(px<0){
						px=px+2*dy1;
					}else{
						if((dx<0&&dy<0)||(dx>0&&dy>0)){
							y=y+1;
						}else{
							y=y-1;
						}
						px=px+2*(dy1-dx1);
					}
					putpixel(x,y,pc);
				}
			}else{
				if(dy>=0){
					x=x1;y=y1;ye=y2;
				}else{
					x=x2;y=y2;ye=y1;
				}
				putpixel(x,y,pc);
				for(i=0;y<ye;i++){
					y=y+1;
					if(py<=0){
						py=py+2*dx1;
					}else{
						if((dx<0&&dy<0)||(dx>0&&dy>0)){
							x=x+1;
						}else{
							x=x-1;
						}
						py=py+2*(dx1-dy1);
					}
					putpixel(x,y,pc);
				}
			}
			}catch(const std::exception&e){std::cout<<e.what()<<std::endl;}
		}
	private:
		std::array<std::array<unsigned char,w>,h>mr;
		unsigned int mw;
		unsigned int mh;
};
int main(void){
	{
		const int w=32;
		const int h=16;
		Raster<w,h>r;
		r.fill('.');
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<double> distx(0,w);
		std::uniform_real_distribution<double> disty(0,h);
		std::vector<char>vglyph{'0','1','2'};
		std::uniform_int_distribution<int> distg(0,vglyph.size()-1);
		for(size_t i=0;i<8;++i){
			r.line(
				distx(mt),					
				disty(mt),					
				distx(mt),					
				disty(mt),					
				vglyph[distg(mt)]
			);
		}
		r.plot(std::cout);
	}
	return EXIT_SUCCESS;
}
