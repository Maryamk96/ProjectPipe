#pragma once
#ifndef  PIPE_H
#define PIPE_H


class Pipe
{
public:
	Pipe();
	virtual void setinput()=0;
	virtual int getinput()=0;
	virtual void setoutput() = 0;
	virtual int getoutput() = 0;

	virtual ~Pipe();

private:
	int  input;
	int output;
	char type;
	bool pipe;
};

#endif // ! PIPE_H