defmodule ApiDemo.Router do
  use ApiDemo.Web, :router

  pipeline :api do
    plug :accepts, ["json"]
    plug :fetch_session
    plug :fetch_flash
    plug :protect_from_forgery
  end

  scope "/", ApiDemo do
    pipe_through :api
    scope "/api", Api do
      scope "/v1.0", V1, as: :v1 do
        resources "/subscribers", SubscriberController
        resources "/subs_groups", SubsGroupController
      end
    end
  end

end
