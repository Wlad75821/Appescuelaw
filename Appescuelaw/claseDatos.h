// ===== claseDatos.h =====

#pragma once

using namespace System;
using namespace System::Collections::Generic;

public ref class Estudiante
{
public:
	String^ usuario;
	String^ password;
	String^ carrera;
	String^ semestre;
	String^ materia;
};

public ref class DatosSistema
{
public:
	static List<Estudiante^>^ estudiantes =
		gcnew List<Estudiante^>();
};
