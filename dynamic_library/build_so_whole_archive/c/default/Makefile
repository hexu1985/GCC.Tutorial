
libraries := lib
programs := app

.PHONY: all $(programs) $(libraries)
all: $(programs)

$(programs) $(libraries):
	$(MAKE) --directory=$@ $(TARGET)

# dependency
$(programs): $(libraries)

clean:
	$(MAKE) TARGET=clean
