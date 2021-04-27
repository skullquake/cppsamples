#ifndef h81e2bd2e954b11eb8e66d37c5ee8332f
#define h81e2bd2e954b11eb8e66d37c5ee8332f
#include<cstdio>
namespace SQ{
	constexpr const char*version="0.0.2";
	class UTest{
		public:
			UTest(const char*pid,int psum=1):
				mid(pid),
				msum(psum),
				maccpas(0),
				macctst(0),
				mver(version)
			{}
			~UTest(){}
			void test(const char*id,int flag){
				if(msum)printf("%s: %s\n",id,flag?"pass":"fail");
				if(flag)++maccpas;++macctst;
			}
			void report(){
				printf("utest version:  %s\n",mver);
				printf("total:  %d\n",macctst);
				printf("passed: %d\n",maccpas);
			}
		private:
			int msum;
			const char*mid;
			unsigned int maccpas;
			unsigned int macctst;
			const char*mver;
	};
}
#endif
