#include <iostream>
#include <cstdlib>
#include <list>
using namespace std;

class Mem {
	public:
		Mem(int s,int e, int v, int h):start(s),end(e),size(v),handle(h){}
		int start;
		int end;
		int size;
		int handle;
};

int count,Maxmem;
list<Mem> m_free;
list<Mem> m_used;

void myNew(int num) {
	list<Mem>::iterator it = m_free.begin();
	while(it != m_free.end()) {
		if(it->size >= num) {
			count++;
			if(it->size == num) {
				Mem t_used = Mem(it->start, it->end, it->size, count);
				m_used.insert(m_used.begin(),t_used);
				m_free.erase(it);
			} else {
				Mem t_used = Mem(it->start, it->start+num-1, num, count);
				m_used.insert(m_used.begin(), t_used);
				it->start = it->start + num;
				it->size = it->size - num;
			}
			cout<<count<<endl;
			return;
		}
		it++;
	}
	cout<<"NULL"<<endl;
	return;
}

void myDel(int num) {
	list<Mem>::iterator it = m_used.begin();
	while(it != m_used.end()) {
		if(it->handle == num) {
			list<Mem>::iterator it2 = m_free.begin();
			while(it2 != m_free.end()) {
				if(it->end < it2->start) {
					if(it->end+1 == it2->start) {
						it2->start = it->start;
						it2->size = it->size + it2->size;
					} else {
						Mem t_free = Mem(it->start, it->end, it->size, -1);
						m_free.insert(it2, t_free);
					}
					m_used.erase(it);
					return;	
				} 
				if(it->start > it2->end) {
					list<Mem>::iterator it3 = it2++;
					if(it3 == m_free.end() || it->end > it3->start) {
						if(it3 == m_free.end()) {
							if(it->start > it2->end+1) {
								Mem t_free = Mem(it->start, it->end, it->size, -1);
								m_free.insert(it3, t_free);
							}
							else {
								it2->end = it->end;
								it2->size = it->size + it2->size;
							}
						} else {
							if(it->start > it2->end+1 && it->end+1 < it3->start) {
								Mem t_free = Mem(it->start, it->end, it->size, -1);
								m_free.insert(it3, t_free);
							} else {
								if(it->start == it2->end+1) {
									it2->end = it->end;
									it2->size = it->size + it2->size;
								}
								if(it->end == it3->start+1) {
									if(it2->end == it3->start+1) {
										it2->end = it3->end;
										it2->size = it2->size+it3->size;
										m_free.erase(it3);
									}
									else {
										it3->start = it->start;
										it3->size = it->size + it3->size;
									}
								}
							}
						} 
						m_used.erase(it);
						return;
					} else {
						continue;
					}
				}	
			}
		}
		it++;
	}
	cout<<"ILLEGAL_OPERATION"<<endl;
	return;
}

void myDef() {
	list<Mem> it=m_free.begin();
	int v=0;
	while(it!=m_free.end()) {
		v=v+it->size;
		it++;
	}
	Mem tf = Mem(Maxmem-v,Maxmem-1,v,-1);
	list<Mem> newone;
	newone.insert(newone.begin(),tf);
	m_free = newone;
	it = m_used.begin();
	int pos = 0;
	while(it!= m_used.end()) {
		it->start = pos;
		it->end = pos+it->size-1;
		pos = it->end+1;
		it++;
	}
	return;
}

int main() {
	int T,num;
	string op;
	while(cin>>T>>Maxmem) {
		count = 0;
		m_free.clear();
		m_used.clear();
		Mem mm = Mem(0,Maxmem-1,Maxmem, -1);
		for(int i=0;i<T;++i) {
			cin>>op;
			if(op == "new") {
				cin>>num;
				myNew(num);
			} else if (op == "del") {
				cin>>num;
				myDel(num);
			} else if(op == "def") {
				myDef();
			}
		}
	}
	return 0;
}
