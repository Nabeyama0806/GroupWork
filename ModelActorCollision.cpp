#include "ModelActorCollision.h"
#include "ModelActor.h"
#include "Collider.h"

//�X�V
void ModelActorCollision::Update()
{
	std::list<ModelActor*> actorList(m_modelActorList);

	//��������ŏՓ˔���
	for (auto it1 = actorList.begin(); it1 != actorList.end(); ++it1)
	{
		//�C�e���[�^������o��
		ModelActor* actor1 = *it1;
		if (actor1->GetName() != "Player" && actor1->GetName() != "FireBottle" &&
			actor1->GetName() != "WaterBottle" && actor1->GetName() != "WindBottle" &&
			actor1->GetName() != "ThunderBottle" && actor1->GetName() != "Water" &&
			actor1->GetName() != "Flush") continue;

		for (auto it2 = actorList.begin(); it2 != actorList.end(); ++it2)
		{			
			ModelActor* actor2 = *it2;

			//�Փ˔���̌`�󂪂Ȃ���΃X�L�b�v
			if (!actor1->GetCollider()) continue;
			if (!actor2->GetCollider()) continue;

			//���g�̓X�L�b�v
			if (actor1 == actor2) continue;

			//�Փ˔���
			if (actor1->GetCollider()->CheckCollision(
				actor1->GetTransform(),
				actor2->GetTransform(), actor2->GetCollider()))
			{
				actor1->OnCollision(actor2);
				actor2->OnCollision(actor1);
			}
		}
	}
}

#ifdef _DEBUG
void ModelActorCollision::Draw()
{
	for (auto it = m_modelActorList.begin(); it != m_modelActorList.end(); ++it)
	{
		ModelActor* actor = *it;
		if (actor->GetCollider())
		{
			actor->GetCollider()->Draw(actor->GetTransform());
		}
	}
}
#endif