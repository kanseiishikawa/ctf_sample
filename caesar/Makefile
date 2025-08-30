COMPILER = g++
CFLAGS   = -g -Wall -O2 -MMD -MP
LDFLAGS  =
LIBS     =
INCLUDE  = 
TARGET   = main
OBJDIR   = ./obj
SOURCES  = $(wildcard *.cpp)
OBJECTS  = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))
DOBJECTS  = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.d))

 $(TARGET): $(OBJECTS) $(LIBS)
	$(COMPILER) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: %.cpp
	@[ -d $(OBJDIR) ]
	$(COMPILER) $(CFLAGS) $(INCLUDE) -o $@ -c $<

all: clean $(TARGET)

clean:
	rm -f $(OBJECTS) $(DOBJECTS) $(TARGET)

-include $(DOBJECTS)
