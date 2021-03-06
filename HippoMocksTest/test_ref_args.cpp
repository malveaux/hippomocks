#include "hippomocks.h"
#include "yaffut.h"

class IRefArg {
public:
	virtual void test() = 0;
};

class IK {
public:
	virtual ~IK() {}
	virtual void f(int &);
	virtual void g(int &) = 0;
	virtual int &h() = 0;
	virtual const std::string &k() = 0;
	virtual void l(IRefArg &refArg) { refArg.test();}
};

FUNC (checkArgumentsAccepted)
{
	MockRepository mocks;
	IK *iamock = mocks.Mock<IK>();
	int x = 42;
	mocks.ExpectCall(iamock, IK::f).With(x);
	mocks.ExpectCall(iamock, IK::g).With(x);
	iamock->f(x);
	iamock->g(x);
}


FUNC (checkArgumentsChecked)
{
	MockRepository mocks;
	IK *iamock = mocks.Mock<IK>();
	int x = 1, y = 2;
	mocks.ExpectCall(iamock, IK::f).With(x);
	mocks.ExpectCall(iamock, IK::g).With(y);
	bool exceptionCaught = false;
	try 
	{
		iamock->f(y);
	}
	catch (HippoMocks::ExpectationException)
	{
		exceptionCaught = true;
	}
	CHECK(exceptionCaught);
	mocks.reset();
}

void plusplus(int &x) 
{ 
	x++; 
}
void plusequals2(int &x) 
{
	x+=2; 
}

FUNC (checkRefArgumentsPassedAsRef)
{
	MockRepository mocks;
	IK *iamock = mocks.Mock<IK>();
	int x = 1, y = 2;
	mocks.ExpectCall(iamock, IK::f).Do(plusplus);
	mocks.ExpectCall(iamock, IK::g).Do(plusequals2);
	iamock->f(x);
	iamock->g(y);
	CHECK(x == 2);
	CHECK(y == 4);
}

FUNC (checkRefReturnValues)
{
	MockRepository mocks;
	IK *iamock = mocks.Mock<IK>();
	int x = 0;
	mocks.ExpectCall(iamock, IK::h).Return(x);
	mocks.ExpectCall(iamock, IK::k).Return("Hello World");
	iamock->h() = 1;
	EQUAL(iamock->k(), std::string("Hello World"));
	EQUAL(x, 1);
}

bool operator==(const IRefArg &a, const IRefArg &b)
{
	return (&a == &b);
}

FUNC (checkRefArgCheckedAsReference)
{
	MockRepository mocks;
	IK *iamock = mocks.Mock<IK>();
	IRefArg *refArg = mocks.Mock<IRefArg>();

	mocks.ExpectCall(iamock, IK::l).With(*refArg);
	iamock->l(*refArg);
}

