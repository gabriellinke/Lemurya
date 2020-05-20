#pragma once

class ListaEntidades;

class Lemurya;

class State
{
	private:
		Lemurya* jogo;

	public:
		State();
		virtual ~State();

		virtual void draw() = 0;
		virtual void update() = 0;
		virtual void input() = 0;
};


