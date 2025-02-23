from helper import *
import pytest

def test_fixUndercuts():
    torus = mrmesh.make_undercut_test_torus(2, 1, 1.5, 10, 10, None)

    dir = mrmesh.Vector3()
    dir.x = 0
    dir.y = 0
    dir.z = 1

    mrmesh.fix_undercuts(torus, dir, 0.2, 0.)

    assert(torus.points.vec.size() > 2900)
