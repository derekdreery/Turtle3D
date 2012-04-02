
CXX  = g++
CXXFLAGS = -g -O2
PROG = prog
OBJS = main.o quaternion.o path.o turtle.o model.o edge.o view.o
HDRS = quaternion.h path.h turtle.h model.h vector3.h edge.h exception.h view.h glutMaster.h glutWindow.h
LIBS = -lGL -lGLU -lglfw -lboost_thread-mt -lglut

#===========================

# Rules
%.o : %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@


all : $(PROG)

$(PROG) : $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LIBS)

clean :
	rm $(OBJS) $(PROG)
