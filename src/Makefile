Vector3D:	Vector3D.o Vector3D_main.o
	g++ $^ -o $@
Vector3D.o:	Vector3D.cxx Vector3D.h
	g++ -c $<
Vector3D_main.o:	Vector3D_main.cxx Vector3D.h
	g++ -c $<

LorentzVector:	Vector3D.o LorentzVector.o LorentzVector_main.o
	g++ $^ -o $@
LorentzVector.o:	LorentzVector.cxx LorentzVector.h Vector3D.h
	g++ -c $<
LorentzVector_main.o:	LorentzVector_main.cxx LorentzVector.h Vector3D.h
	g++ -c $<