/**********************************************************************************************
  LATENCY COMPARISION BETWEEN STD::QUEUE AND STD::VECTOR
  SAGA@SAGA-Inspiron-5520:~/Practice/design_patterns/design_pattern_cpp$ c++ latency_comparison.cpp -std=c++11 -o latency
  SAGA@SAGA-Inspiron-5520:~/Practice/design_patterns/design_pattern_cpp$ ./latency 
  ====================================
  Q Size: 0
  Q Push Latency : 0.014169
  Q Size: 100000
  Q Pop Latency : 0.00867191
  Q Size: 0
  Q Push Latency : 0.0123537
  Q swapIterClr Latency : 0.00375147
  Q Size: 0
  ====================================
  V Size: 0
  V Pash Latency : 0.0113719
  V Size: 100000
  V PoP Latency : 0.917398
  V Size: 0
  V Pash Latency : 0.0117648
  V swapIterClr Latency : 0.000856691
  V Size: 0
  ====================================
 ***********************************************************************************************/

#include <queue>
#include <vector>
#include <iostream>
#include <string>
#include <chrono>
#include <sys/time.h>

using namespace std;

class TestQ
{
	private:
		std::queue<std::string *> _q;
		std::queue<std::string *> _tq;

	public:
		TestQ()
		{}

		int getQSize() const
		{
			return _q.size();
		}

		void push()
		{
			auto start = std::chrono::high_resolution_clock::now();
			for(int i = 0; i < 100000; i++)
			{
				_q.emplace(new std::string("Queue"));
			}
			auto finish = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed = finish - start;
			cout<<"Q Push Latency : "<<elapsed.count()<<endl;
		}

		void pop()
		{
			auto start = std::chrono::high_resolution_clock::now();
			while(_q.size())
			{
				std::string *s =(std::string *) _q.front();
				if (s && !s->empty())
				{
					_q.pop();
					delete s;
					s =  NULL;
				}
			}
			auto finish = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed = finish - start;
			cout<<"Q Pop Latency : "<<elapsed.count()<<endl;
		}

		void swapIterClr()
		{
			auto start = std::chrono::high_resolution_clock::now();
			std::swap(_q,_tq);
			while (!_tq.empty())
			{
				_tq.front();
				_tq.pop();
			}
			auto finish = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed = finish - start;
			cout<<"Q swapIterClr Latency : "<<elapsed.count()<<endl;
		}
};


class TestV
{
	private:
		std::vector<std::string *> _v;
		std::vector<std::string *> _tv;
	public:
		TestV()
		{
			_v.reserve(100000);
			_tv.reserve(100000);
		}

		int getVSize() const
		{
			return _v.size();
		}

		void push()
		{
			auto start = std::chrono::high_resolution_clock::now();
			for(int i = 0; i < 100000; i++)
			{
				_v.emplace_back(new std::string("Vector"));
			}
			auto finish = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed = finish - start;
			cout<<"V Pash Latency : "<<elapsed.count()<<endl;
		}

		void pop()
		{
			auto start = std::chrono::high_resolution_clock::now();
			auto it = _v.begin();
			while(it != _v.end())
			{
				it = _v.erase(it); 
			}
			auto finish = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed = finish - start;
			cout<<"V PoP Latency : "<<elapsed.count()<<endl;
		}

		void swapIterClr()
		{
			auto start = std::chrono::high_resolution_clock::now();
			std::swap(_v,_tv);
			for (auto & it : _tv)
			{}
			_tv.clear();
			auto finish = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed = finish - start;
			cout<<"V swapIterClr Latency : "<<elapsed.count()<<endl;
		}
};

int main()
{
	std::cout<<"===================================="<<std::endl;
	TestQ *q = new TestQ();
	cout<<"Q Size: "<<q->getQSize()<<endl;
	q->push();
	cout<<"Q Size: "<<q->getQSize()<<endl;
	q->pop();
	cout<<"Q Size: "<<q->getQSize()<<endl;
	q->push();
	q->swapIterClr();
	cout<<"Q Size: "<<q->getQSize()<<endl;

	std::cout<<"===================================="<<std::endl;
	TestV *v = new TestV();
	cout<<"V Size: "<<v->getVSize()<<endl;
	v->push();
	cout<<"V Size: "<<v->getVSize()<<endl;
	v->pop();
	cout<<"V Size: "<<v->getVSize()<<endl;
	v->push();
	v->swapIterClr();
	cout<<"V Size: "<<v->getVSize()<<endl;
	std::cout<<"===================================="<<std::endl;
	return 0;
}
