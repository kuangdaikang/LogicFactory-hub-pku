import gym
from arguments import get_args
from stable_baselines3 import PPO


def main(arguments):
    if arguments.feature_mode == 'normal':
        obs_dim = 81
    elif arguments.feature_mode == 'glitch':
        obs_dim = 89
    elif arguments.feature_mode == 'basic':
        obs_dim = 14
    else:
        raise NotImplementedError
    env = gym.make('gym_genus:genus-v0', lib_file="/rshome/sunan.zou/nas/PowerAwareSynthesis/netlist/gsc145nm.lib",
                   feature_mode=args.feature_mode, obs_dim=obs_dim)
    model = PPO("MlpPolicy", env, tensorboard_log=arguments.log, verbose=1, batch_size=16, n_steps=32, device='cpu')
    model.save(arguments.model_name)

    src = open(arguments.train_list, "r")
    for line in src.readlines():
        print(line)
        model = PPO.load(arguments.model_name, env, device='cpu')
        env.setup(arguments.train_dir + '/' + line)
        for i in range(arguments.epoch):
            model.learn(total_timesteps=arguments.action_length, reset_num_timesteps=False)
        env.stop()
        model.save(arguments.model_name)


if __name__ == '__main__':
    args = get_args()  # Parse arguments from command line
    main(args)

