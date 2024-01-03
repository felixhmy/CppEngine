// Realizado por: Félix Hernández Muñoz-Yusta

namespace engine
{
	class Timer
	{
	public:
		// En el constructor inicializa el tiempo a 0.
		Timer() { }

		float get_elapsed_seconds() const // Aqui se mira cuanto tiempo a pasado y se retorna
		{
			return 1.f / 60.f;
		}
	};
}