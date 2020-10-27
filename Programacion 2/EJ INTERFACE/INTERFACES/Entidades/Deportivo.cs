﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    class Deportivo:Auto,IAFIP
    {
        protected int _caballosFuerza;

        public Deportivo(double precio, string patente, int hp):base(precio,patente)
        {
            this._caballosFuerza = hp;
        }
        double IAFIP.CalcularImpuesto()
        {
            return _precio * 1.28;
        }

    }
}
