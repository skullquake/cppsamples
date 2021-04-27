#ifdef FOO
#endif
#ifndef FOO
#endif
#if defined(FOO)
#endif
#if defined(FOO)||defined(BAR)
#if defined(BAZ)&&defined(QUX)
#endif
#if defined(BAZ)&&!defined(QUX)
#endif
#endif
int main(void){}
