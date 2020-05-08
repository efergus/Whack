
worker := worker.make
WORK = cp $(worker) ./$@/$(worker) && make -f worker.make -C ./$@ lib_dir=../lib flags="-std=c++17 $(flags)"
BURY = rm ./$@/$(worker)
GUI: tile
	$(eval flags += -I../tile)
	@$(WORK) lib_deps=mod
	@$(BURY)
tile:
	@$(WORK)
	@$(BURY)

.PHONY: tile

visual: GUI
	$(CXX) -o $@ GUI/visual.cpp $(CXXFLAGS) -Llib $(patsubst lib/lib%.a, -l%, $(wildcard lib/lib*.a)) -lglfw -lGLEW -lGL -Itile -std=c++17