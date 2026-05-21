#pragma once

using namespace System;

public ref class Usuario
{
public:
	String^ usuario;
	String^ clave;
	String^ rol;

	Usuario(String^ u, String^ c, String^ r)
	{
		usuario = u;
		clave = c;
		rol = r;
	}
};